from subprocess import Popen, PIPE
from enum import Enum
from os import getcwd
from sys import argv
from junit_xml import TestSuite, TestCase


class State(Enum):
    OK = 0
    KO = 1
    CRASH = 2


def print_result(test, result, return_code, print_details):
    expected_output = test["expected_output"]
    expected_return_code = test["expected_return_code"]

    if return_code == 139:
        print(
            f"Test \"{test['name']}\" failed: the program crashed with signal {return_code}")
        return State.CRASH
    if result != expected_output:
        print(
            f"Test \"{test['name']}\" failed: expected output is \n{expected_output}\nactual output is \n{result}\n")
        return State.KO
    else:
        if return_code != expected_return_code:
            print(
                f"Test \"{test['name']}\" failed: expected return code is {expected_return_code}, actual return code is {return_code}")
            return State.KO
        else:
            if print_details:
                print(f"Test '{test['name']}' passed")
            return State.OK


def test_command(test, print_details):
    result = ""
    process = Popen([test["program"], test["file"]],
                    cwd=getcwd(),
                    stdout=PIPE,
                    stderr=PIPE,
                    stdin=PIPE,
                    universal_newlines=True)

    while process.poll() is None:
        for command in test["command"]:
            process.stdin.write(command + "\n")
        process.stdin.flush()
        child_output = process.stdout.readline()
        result += child_output

    process.stdin.close()
    process.stdout.close()
    return print_result(test, result, process.returncode, print_details)


# Define the tests
tests = [
    {
        "name": "Simple exit",
        "program": "./nanotekspice",
        "file": "tests/invalid_file.nts",
        "command": ["exit"],
        "expected_return_code": 84,
        "expected_output": "",
    }, {
        "name": "Simple display",
        "program": "./nanotekspice",
        "file": "tests/valid_file.nts",
        "command": ["display", "exit"],
        "expected_return_code": 0,
        "expected_output":
            "> tick: 0\n" +
            "input(s):\n" +
            "output(s):\n" +
            "  out: 0\n" +
            "> ",
    },
]


def generate_file(result):
    test_cases = []
    for i, test in enumerate(tests):
        test_cases.append(TestCase(test["name"], classname="nanotekspice",
                                   stdout=result[i].name, stderr="",
                                   elapsed_sec=0.0, status=result[i].name))
    test_suite = [TestSuite("nanotekspice", test_cases)]
    with open("functests.xml", "w") as f:
        TestSuite.to_file(f, test_suite)


def main():
    test_nb = tests.__len__()
    result = []
    print_details = False
    if len(argv) > 1 and (argv[1] == "--help" or argv[1] == "-h"):
        print("Usage: ./tester.py [--verbose|-v]")
        return 0
    if len(argv) > 1 and (argv[1] == "--verbose" or argv[1] == "-v"):
        print_details = True
    if len(argv) > 1 and (argv[1] != "--verbose" and argv[1] != "-v"):
        print("Usage: ./tester.py [--verbose|-v]")
        for i in argv:
            print(i)
        return 84
    for test in tests:
        result.append(test_command(test, print_details))
    print(
        f"[====] Synthesis: Tested: {test_nb} | Passing: {result.count(State.OK)} | Failing: {result.count(State.KO)} | Crashing: {result.count(State.CRASH)}")
    generate_file(result)
    return 0


if __name__ == "__main__":
    main()
