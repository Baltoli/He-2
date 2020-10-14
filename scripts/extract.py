import os
import subprocess
import drclient
import common

parent_folder = os.environ.get('EXALGO_PARENT_FOLDER')

'''
this function invokes the executable under instruction tracing
'''
def run_instrace(path, executable, args, debug, in_image):
        filter_folder = os.environ.get('EXALGO_FILTER_FOLDER')
        exe_basename = os.path.basename(executable)

        filter_path = os.path.join(filter_folder, f'filter_{exe_basename}.log')

        drclient.run_drclients(path, executable, args, debug, 'funcwrap,instrace,memdump',
                      'func', filter_path, in_image, 'instrace')
        drclient.run_drclients(path, executable, args, debug, 'funcwrap,instrace',
                      'func', filter_path, in_image, 'ins_distrace')

        
def run_buildex(executable, in_image, out_image, debug, debug_level, dump, opts):
        parent_folder = os.environ.get('EXALGO_PARENT_FOLDER')
        buildex_dir = os.path.join(parent_folder, 'build', 'postprocess', 'buildex', 'main')
        buildex_exe = os.path.join(buildex_dir, 'buildex')

        command = [
            buildex_exe,
            '-exec', executable,
            '-in_image', in_image,
            '-out_image', out_image,
            '-debug', common.boolstr(debug),
            '-debug_level', debug_level,
            '-dump', dump
        ]

        subprocess.run(command)
