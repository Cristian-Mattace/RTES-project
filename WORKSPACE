# The command to run a test => bazel test --cxxopt=-std=c++14 --test_output=all --verbose_failures --symlink_prefix=/ //test:singly_linked_list_test
# All the references about Bazel => https://google.github.io/googletest/quickstart-bazel.html
# Use this command to clean => bazel clean --expunge

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
  strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
)