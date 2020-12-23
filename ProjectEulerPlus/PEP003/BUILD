cc_library(
    name = "PEP003",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "PEP003_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//ProjectEulerPlus/PEP003",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "PEP003_bin",
    deps = [
        "//ProjectEulerPlus/PEP003",
    ],
)
