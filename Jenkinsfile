pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        sh '''qmake  ui-qt/Detector.pro -spec linux-g++
qmake_all
make'''
      }
    }
  }
}