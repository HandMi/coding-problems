cc_library(
    name = "AOC20_5_2",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "AOC20_5_2_bin",
    deps = [
        "//AdventOfCode/2020/5/2:AOC20_5_2",
    ],
)
