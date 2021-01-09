load("@rules_java//java:defs.bzl", "java_binary", "java_library")

java_library(
    name = "Percolation",
    srcs = ["src/Percolation.java"],
    deps = [
        "@algs4//jar",
    ],
)

java_binary(
    name = "PercolationVisualizer",
    srcs = [
        "src/PercolationVisualizer.java",
    ],
    data = glob(["data/*.txt"]),
    deps = [
        ":Percolation",
        "@algs4//jar",
    ],
)
