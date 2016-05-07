# ProtobufSerializeBench

Benchmark comparing Protobufs SerializeToString/ParseFromString vs CopyFrom performance.

## Initial Results for 1000 iterations

SerializeToString/ParseFromString: 0.0115321000

SerializeToString (only):          0.0032351000

CopyFrom:                          0.0073221000


## Instructions 


    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ ./benchmark
