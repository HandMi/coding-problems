cc_library(
    name = "PEP001",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP001_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP001",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP001_bin",
    deps = [
        "//ProjectEulerPlus/PEP001",
    ],
)
