# ProtobufSerializeBench

Benchmark comparing Protobufs SerializeToString/ParseFromString vs CopyFrom performance.

## Initial Results for 1000 iterations

SerializeToString: 0.010511000
CopyFrom: 0.0052841000


## Instructions 


    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ ./benchmark
