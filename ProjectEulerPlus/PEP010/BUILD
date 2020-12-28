cc_library(
    name = "PEP010",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP010_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP010",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP010_bin",
    deps = [
        "//ProjectEulerPlus/PEP010",
    ],
)
