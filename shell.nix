{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  packages = with pkgs; [
    minilibx
    xorg.libX11
    xorg.libXext
    gnumake
    clang-tools
    gdb
    norminette
    compiledb
  ];
}
