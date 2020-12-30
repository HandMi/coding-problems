cc_library(
    name = "PEP012",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP012_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP012",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP012_bin",
    deps = [
        "//ProjectEulerPlus/PEP012",
    ],
)
