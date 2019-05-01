from building import *

cwd  = GetCurrentDir()
src  = Glob('*.c')
path = [cwd + '/inc']

if GetDepend('PKG_USING_DIGITALCTRL'):
    src += Glob('src/dc_pid.c')

group = DefineGroup('DigitalCtrl', src, depend = ['PKG_USING_DIGITALCTRL'], CPPPATH = path)

Return('group')
