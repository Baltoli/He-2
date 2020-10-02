#!/bin/bash

SCRIPTS_DIR=$(dirname $(realpath -s "${BASH_SOURCE[0]}"))
ROOT_DIR=$(realpath "$SCRIPTS_DIR/..")

export EXALGO_PARENT_FOLDER=$ROOT_DIR
export EXALGO_HALIDE_FOLDER=$ROOT_DIR/generated_files/halide_files
export EXALGO_OUTPUT_FOLDER=$ROOT_DIR/generated_files/output_files
export EXALGO_FILTER_FOLDER=$ROOT_DIR/generated_files/filter_files
export EXALGO_LOG_FOLDER=$ROOT_DIR/generated_files/log
export EXALGO_IMAGE_FOLDER=$ROOT_DIR/images
export EXALGO_TEST_FOLDER=$ROOT_DIR/tests
