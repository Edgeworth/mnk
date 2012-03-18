#!/usr/bin/env python
import os, sys

def error(val):
	if val != 0:
		print "Error during build."
		sys.exit(1)

os.chdir('cmake')

error(os.system('cmake .'))
error(os.system('make'))
