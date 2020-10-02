#!/bin/bash

SCRIPTS_DIR=$(dirname $(realpath -s "${BASH_SOURCE[0]}"))
ROOT_DIR=$(realpath "$SCRIPTS_DIR/..")

cd $ROOT_DIR

mkdir -p generated_files/output_files
mkdir -p generated_files/filter_files
mkdir -p generated_files/halide_files
mkdir -p generated_files/log
