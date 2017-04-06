pipeline {
  agent any
  stages {
    stage('build') {
      node {
        sh '''qmake  ui-qt/Detector.pro -spec linux-g++
make'''
      }
    }
  }
}
