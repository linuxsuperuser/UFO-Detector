pipeline {
  agent any
  stages {
    stage('build') {
	wrap([$class: 'Xvfb']) {
      steps {
        sh '''qmake  ui-qt/Detector.pro -spec linux-g++
make'''
      }
	  }
    }
  }
}
