cc_library(
    name = "AOC20_05_2",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "AOC20_05_2_bin",
    deps = [
        "//AdventOfCode/2020/05/2:AOC20_05_2",
    ],
)
