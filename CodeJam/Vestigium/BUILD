cc_library(
    name = "Vestigium",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/*.h"]),
    linkopts = ["-pthread"],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "CJ_Vestigium_test",
    srcs = glob(["test/*.cpp"]),
    deps = [
        "//CodeJam/Vestigium",
        "@gtest//:gtest_main",
    ],
    data = glob(["data/*.txt"]),
)

cc_binary(
    name = "CJ_Vestigium_bin",
    deps = [
        "//CodeJam/Vestigium",
    ],
)
