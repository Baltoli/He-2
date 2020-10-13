#!/bin/bash

LOGDIR="$EXALGO_OUTPUT_FOLDER"

"$DYNAMORIO_HOME/bin64/drrun" \
  -root "$DYNAMORIO_HOME" \
  -t drcov \
  -dump_text \
  -logdir "$LOGDIR" \
  -- $@
