pipeline {
    agent {
        docker {
            image 'epitechcontent/epitest-docker:latest'
            args '-v /var/run/docker.sock:/var/run/docker.sock'
        }
    }
    environment {
        // Set the ssh key for the mirror using secret private key
        PRIVATE_KEY = credentials('EPITECH_SSH_KEY')
        MIRROR_URL = 'git@github.com:EpitechPromo2027/B-OOP-400-NAN-4-1-tekspice-thomas.boue.git'
    }
    stages {
        stage('🕵️ Lint') {
            steps {
                // Download the coding style checker
                sh 'wget https://raw.githubusercontent.com/Epitech/coding-style-checker/main/coding-style.sh'
                sh 'chmod +x coding-style.sh'
                sh 'chmod +x debug-coding-style.sh'

                // Run check.sh in the current directory (it accept a directory source as argument and a directory when the report will be generated)
                sh './debug-coding-style.sh . .'

                // Parse the report and fail the build if the quality gate is not passed
                script {
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
                script {
                    if (!fileExists('nanotekspice')) {
                        error "The binary file does not exist"
                    }
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
                // Remove the mirror if it already exists
                sh "git remote remove mirror || true"

                // Add the mirror
                sh "git remote add mirror ${MIRROR_URL}"

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
        post {
            // Clean after build
            always {
                cleanWs(cleanWhenNotBuilt: true,
                        deleteDirs: true,
                        disableDeferredWipeout: true,
                        notFailBuild: true,
                        patterns: [[pattern: '.gitignore', type: 'INCLUDE'],
                                   [pattern: '.propsfile', type: 'EXCLUDE']])
            }
        }
}