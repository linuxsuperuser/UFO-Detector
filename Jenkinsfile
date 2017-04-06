pipeline {
  agent any
  stages {
    stage('build') {
      steps {
	  node {
	     sh '''qmake  ui-qt/Detector.pro -spec linux-g++
make'''
	  }
     
      }
    }
  }
}
