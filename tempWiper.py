import os
from glob import glob

def wipedir(curDir):
	for subfolder in sorted(glob(curDir + '*/')):
		wipedir(subfolder)
	for fileName in os.listdir(curDir):
		os.remove(curDir + fileName)
	os.rmdir(curDir)

def seekanddestroy(curDir):
	subfolderList = sorted(glob(curDir + '*/'))

	if (curDir + '.vscode/') in glob(curDir + '.vscode/'):
		wipedir(curDir + '.vscode/')
		print('Found {}...'.format(curDir + '.vscode/'))
		subfolderList = sorted(glob(curDir + '*/'))

	for fileExecutable in sorted(glob(curDir + '*.exe')):
		os.remove(fileExecutable)
		print('Found {}...'.format(fileExecutable))
	for fileOctal in sorted(glob(curDir + '*.o')):
		os.remove(fileOctal)
		print('Found {}...'.format(fileOctal))
	for fileGmonOut in sorted(glob(curDir + 'gmon.out')):
		os.remove(fileGmonOut)
		print('Found {}...'.format(fileGmonOut))
	for subfolder in subfolderList:
		seekanddestroy(subfolder)

seekanddestroy('Vault/')