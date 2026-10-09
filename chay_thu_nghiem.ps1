$so_lan = 5
$chuong_trinh = @("quicksort", "heapsort", "mergesort", "stdsort")
$file_ket_qua = "results\ket_qua.csv"

New-Item -ItemType Directory -Force -Path results | Out-Null
"thuat_toan,file,lan_chay,thoi_gian_ms,kiem_tra" | Out-File $file_ket_qua -Encoding ascii

foreach ($ct in $chuong_trinh) {
    for ($i = 1; $i -le 10; $i++) {
        $file = "data\seq$i.txt"
        for ($lan = 1; $lan -le $so_lan; $lan++) {
            $kq = & ".\$ct.exe" $file
            $phan = $kq -split ","
            "$($phan[0]),seq$i,$lan,$($phan[2]),$($phan[3])" | Out-File $file_ket_qua -Append -Encoding ascii
            Write-Host "$ct seq$i lan $lan : $($phan[2]) ms ($($phan[3]))"
        }
    }
}
Write-Host "Xong. Ket qua luu tai $file_ket_qua"