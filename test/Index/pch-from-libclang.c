// Check that clang can use a PCH created from libclang.
// RUN: c-index-test -write-pch %t.h.pch %s -fmodules -fmodules-cache-path=%t.mcp -target x86_64-apple-darwin
// RUN: %clang -fsyntax-only -include %t.h %s -Xclang -verify -fmodules -fmodules-cache-path=%t.mcp -Xclang -detailed-preprocessing-record -target x86_64-apple-darwin

// expected-no-diagnostics

#ifndef HEADER
#define HEADER

struct S { int x; };

#else

void test(struct S *s) {
  s->x = 0;
}

#endif