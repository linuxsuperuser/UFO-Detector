node {
  wrap([$class: 'Xvfb']) {
   pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        sh '''qmake  ui-qt/Detector.pro -spec linux-g++
make'''
      }
    }
  }
}
  }
}
