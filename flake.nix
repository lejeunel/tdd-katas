{
  description = "A Nix-flake devshell for TDD Katas in C++";

  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";

  outputs =
    {
      nixpkgs,
      ...
    }:
    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forEachSupportedSystem =
        f: nixpkgs.lib.genAttrs supportedSystems (system: f { pkgs = import nixpkgs { inherit system; }; });
    in
    {
      devShells = forEachSupportedSystem (
        { pkgs }:
        {
          default = pkgs.mkShell {

            packages = with pkgs; [
              clang-tools
              ccls
              gnumake
              cmake
              gcc
              catch2_3
            ];
            shellHook = ''
              export CPATH="${pkgs.catch2_3}/include"
            '';
          };
        }
      );
    };
}
