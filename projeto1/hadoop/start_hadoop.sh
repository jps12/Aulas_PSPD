#!/bin/bash

MAPPER_FILE=mapper.py
REDUCER_FILE=reducer.py
INPUT_FILE=/input/input.txt
OUTPUT_DIR=/output

$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar \
    -files $MAPPER_FILE,$REDUCER_FILE \
    -mapper $MAPPER_FILE \
    -reducer $REDUCER_FILE \
    -input $INPUT_FILE \
    -output $OUTPUT_DIR