pipeline {
  agent any
  wrap([$class: 'Xvfb']) {
  stages {
    stage('build') {
		node {
			
			     steps {
						sh '''qmake  ui-qt/Detector.pro -spec linux-g++
						make'''
				}
			
		} 
    }	
  }
  }
}
