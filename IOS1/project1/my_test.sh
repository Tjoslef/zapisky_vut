#!/bin/sh
#Zakladni test list -s flag
setUp() {

  # Create entry 1.conf
  cat > "loader/entries/c.conf" <<EOF
title Fedora Linux 41 with debug
version 6.12.5-200.fc41.x86_64+debug
linux /vmlinuz-6.12.5-200.fc41.x86_64
initrd /initramfs-6.12.5-200.fc41.x86_64.img
options root=UUID=cf5d1643-42a9-4168-a17e-c651f367f367rhgb quiet debug
vutfit_default n
sort-key aaa
EOF

  # Create entry 2.conf
  cat > "loader/entries/b.conf" <<EOF
title Fedora Linux 41
version 6.12.5-200.fc41.x86_64
linux /vmlinuz-6.12.5-200.fc41.x86_64
initrd /initramfs-6.12.5-200.fc41.x86_64.img
options root=UUID=cf5d1643-42a9-4168-a17e-c651f367f367rhgb quiet
vutfit_default y
sort-key bbb
EOF

  # Create entry 3.conf
  cat > "loader/entries/a.conf" <<EOF
title Linux from Scratch
version 1.0
linux /vmlinuz-5.11.1.x86_64
initrd /initramfs-5.11.1.x86_64
options root=UUID=cf5d1643-42a9-4168-a17e-c651f367f367rhgb quiet debug
vutfit_default n
EOF
}
testList_1() {
  # Expected output
  expected=$(cat <<EOF
Fedora Linux 41 with debug (6.12.5-200.fc41.x86_64+debug, /vmlinuz-6.12.5-200.fc41.x86_64)
Fedora Linux 41 (6.12.5-200.fc41.x86_64, /vmlinuz-6.12.5-200.fc41.x86_64)
Linux from Scratch (1.0, /vmlinuz-5.11.1.x86_64)
EOF
  )

  # Actual output
  actual=$(bash /home/tjoslef/skola/vut/IOS1/project1/bootutil.sh list -s | tr -d '\n')

  # Normalize outputs for comparison
  expected_normalized=$(echo "${expected}" | tr -d '\n'  | sort -k1)
  actual_normalized=$(echo "${actual}" | tr -d '\n'  | sort -k1)

  # Debug output
  echo "=== Expected ==="
  echo "${expected_normalized}"
  echo "=== Actual ==="
  echo "${actual_normalized}"
  echo "================"

  # Assert equality
  assertEquals "LIST output mismatch" "${expected_normalized}" "${actual_normalized}" || \
    diff -u <(echo "${expected_normalized}") <(echo "${actual_normalized}")
  exit_code=$?
  assertTrue "Command failed with exit code: ${exit_code}" ${SHUNIT_TRUE}
}

# Test case for list output with -f flag
testList_2() {
  expected=$(cat <<EOF
Linux from Scratch (1.0, /vmlinuz-5.11.1.x86_64)
Fedora Linux 41 (6.12.5-200.fc41.x86_64, /vmlinuz-6.12.5-200.fc41.x86_64)
Fedora Linux 41 with debug (6.12.5-200.fc41.x86_64+debug, /vmlinuz-6.12.5-200.fc41.x86_64)
EOF
  )

  actual=$(bash /home/tjoslef/skola/vut/IOS1/project1/bootutil.sh list -f | tr -d '\n')
  actual_normalized=$(echo "${actual}" | tr -d '\n')
  expected_normalized=$(echo "${expected}" | tr -d '\n')


  echo "=== Expected ==="
  echo "${expected_normalized}"
  echo "=== Actual ==="
  echo "${actual}"
  echo "================"

  assertEquals "LIST output mismatch (-f flag)" "${expected_normalized}" "${actual}" || \
    diff -u <(echo "${expected_normalized}") <(echo "${actual}")

  exit_code=$?
  assertTrue "Command failed with exit code: ${exit_code}" ${SHUNIT_TRUE}
}

# Test case for combined -s and -t flags
testListCombinedFlags() {
  # Expected output
  expected=$(cat <<EOF
Fedora Linux 41 with debug (6.12.5-200.fc41.x86_64+debug, /vmlinuz-6.12.5-200.fc41.x86_64)
Fedora Linux 41 (6.12.5-200.fc41.x86_64, /vmlinuz-6.12.5-200.fc41.x86_64)
EOF
  )

  # Actual output
  actual=$(bash /home/tjoslef/skola/vut/IOS1/project1/bootutil.sh list -s -t 'Fedora')
  actual_normalized=$(echo "${actual}" | tr -d '\n')
  expected_normalized=$(echo "${expected}" | tr -d '\n')

  # Debug output
  echo "=== Expected (-s -t Fedora) ==="
  echo "${expected_normalized}"
  echo "=== Actual (-s -t Fedora) ==="
  echo "${actual_normalized}"
  echo "========================="

  # Assert equality
  assertEquals "Combined flags mismatch (-s -t)" "${expected_normalized}" "${actual_normalized}" || \
    diff -u <(echo "${expected}") <(echo "${actual}")
}

# Test case for -k (kernel regex filter) flag
testListKernelFilter() {
  # Expected output
  expected=$(cat <<EOF
Fedora Linux 41 (6.12.5-200.fc41.x86_64, /vmlinuz-6.12.5-200.fc41.x86_64)
Fedora Linux 41 with debug (6.12.5-200.fc41.x86_64+debug, /vmlinuz-6.12.5-200.fc41.x86_64)
EOF
  )

  # Actual output
  actual=$(bash /home/tjoslef/skola/vut/IOS1/project1/bootutil.sh list -k 'fc41\.x86_64')
  actual_normalized=$(echo "${actual}" | tr -d '\n')
  expected_normalized=$(echo "${expected}" | tr -d '\n')

  # Debug output
  echo "=== Expected (-k) ==="
  echo "${expected_normalized}"
  echo "=== Actual (-k) ==="
  echo "${actual_normalized}"
  echo "====================="

  # Assert equality
  assertEquals "Kernel filter mismatch (-k)" "${expected_normalized}" "${actual_normalized}" || \
    diff -u <(echo "${expected}") <(echo "${actual}")
}
testDuplicate_k() {
  local expected_file="/home/tjoslef/skola/vut/IOS1/project1/loader/entries/a1.conf"

  local expected_content=$'title Fedora Linux 41\nversion 6.12.5-200.fc41.x86_64\nlinux Scratch\ninitrd /initramfs-6.12.5-200.fc41.x86_64.img\noptions root=UUID=cf5d1643-42a9-4168-a17e-c651f367f367rhgb quiet\nvutfit_default y\nsort-key bbb'

  bash /home/tjoslef/skola/vut/IOS1/project1/bootutil.sh duplicate -k 'Scratch' -d "$expected_file"

  assertTrue "File ${expected_file} should exist" "[ -f '${expected_file}' ]"

  local actual_content
  actual_content=$(<"$expected_file")
  assertEquals "File content mismatch (-k)" "$expected_content" "$actual_content" || \
      diff -y --suppress-common-lines <(echo "$expected_content") <(echo "$actual_content")
    rm "$expected_file"
}

. /home/tjoslef/Stažené/sys_package/shunit2-2.1.8/shunit2
