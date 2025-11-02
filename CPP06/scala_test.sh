#!/usr/bin/env bash
# ...existing code...
# quick test runner for ScalarConverter (expects ./ScalarConverter in cwd)

cases=(
  "a" "0" "!" " " 
  "31" "32" "126" "127"
  "42" "42.0f" "42.0" "1.23" "1.0" "1.0f"
  "nan" "nanf" "+inf" "-inf" "+inff" "-inff"
  "1e40" "1e-40" "12345678901234567890" "abc" "12x34" ""
  "-42" "-42.0f" "126.999" "127.0"
)

exe="./ScalarConverter"
if [ ! -x "$exe" ]; then
  echo "Executable $exe not found or not executable. Build first (make / g++ ...)"; exit 1
fi

for lit in "${cases[@]}"; do
  # show a visible marker for empty string test
  if [ -z "$lit" ]; then
    display="(empty)"
  else
    display="$lit"
  fi
  printf "\n=== input: %s ===\n" "$display"
  "$exe" "$lit"
done
# ...existing code...