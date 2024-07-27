{ pkgs }: {
  deps = [
    pkgs.bc
    pkgs.bashInteractive
    pkgs.nodePackages.bash-language-server
    pkgs.man
  ];
}