{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  buildInputs = with pkgs; [
    xorg.libX11
    xorg.libXext
    freetype
  ];
  nativeBuildInputs = with pkgs; [
    clang-tools
    pkg-config
    gcc
    gnumake
  ];
  packages = with pkgs; [
    gdb
    norminette
    compiledb
  ];
}
