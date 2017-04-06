pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        sh '''qmake_all
make'''
      }
    }
  }
}