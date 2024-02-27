pipeline {
    agent {
        docker {
            image 'ghcr.io/epitech/coding-style-checker:latest'
        }
    }
    environment {
        // Set the ssh key for the mirror using secret private key
        PRIVATE_KEY = credentials('EPITECH_SSH_KEY')
    }
    stages {
        stage('🕵️ Lint') {
            steps {
                // Run check.sh in the current directory (it accept a directory source as argument and a directory when the report will be generated)
                sh 'check.sh . .'

                // Parse the report and fail the build if the quality gate is not passed
                def report = readFile 'coding-style-reports.log'
                def errors = report.readLines()
                for (error in errors) {
                    def file = error.split(':')[0]
                    def line = error.split(':')[1]
                    def type = error.split(':')[2]
                    def code = error.split(':')[3]
                    echo "File: ${file}, Line: ${line}, Type: ${type}, Code: ${code}"
                }
                // Fail the build if the quality gate is not passed
                if (errors.size() > 0) {
                    error "Too many coding style errors"
                }

                // Archive the report
                archiveArtifacts 'coding-style-reports.log'

                // Publish the report
                publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: true, reportDir: '.', reportFiles: 'coding-style-reports.log', reportName: 'Coding Style Report', reportTitles: ''])
            }
        }
        stage('🏗️ Build') {
            steps {
                // Run the build
                sh 'make'

                // Check file presence (e.g. binary, library, etc.)
                if (fileExists('nanotekspice')) {
                    echo 'nanotekspice binary found'
                } else {
                    error 'nanotekspice binary not found'
                }

                // Archive the binary
                archiveArtifacts 'nanotekspice'
            }
        }
        stage('🪞 Mirror') {
            when {
                branch 'main'
            }
            steps {
                // Mirror the repository
                def mirror = 'git@github.com:EpitechPromo2027/B-OOP-400-NAN-4-1-tekspice-thomas.boue.git'

                // Remove the mirror if it already exists
                sh "git remote remove mirror || true"

                // Add the mirror
                sh "git remote add mirror ${mirror}"

                // Setup the ssh key for the mirror
                withCredentials([sshUserPrivateKey(credentialsId: 'EPITECH_SSH_KEY', keyFileVariable: 'PRIVATE_KEY')]) {
                    sh 'echo "${PRIVATE_KEY}" > ~/.ssh/id_rsa'
                    sh 'chmod 600 ~/.ssh/id_rsa'
                    sh 'ssh-keyscan github.com >> ~/.ssh/known_hosts'
                }

                // Push the mirror
                sh 'git push --mirror mirror --force'
            }
        }
    }
}