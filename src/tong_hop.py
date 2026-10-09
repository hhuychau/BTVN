import pandas as pd
import matplotlib.pyplot as plt

thu_tu = ["QuickSort", "HeapSort", "MergeSort", "std::sort"]

df = pd.read_csv("results/ket_qua.csv")
df["day"] = df["file"].str.replace("seq", "").astype(int)

trung_binh = df.groupby(["day", "thuat_toan"])["thoi_gian_ms"].mean().unstack()[thu_tu].round(2)
do_lech = df.groupby(["day", "thuat_toan"])["thoi_gian_ms"].std().unstack()[thu_tu].round(2)

trung_binh.to_csv("results/bang_trung_binh.csv", index_label="day")
do_lech.to_csv("results/bang_do_lech_chuan.csv", index_label="day")

print("BANG THOI GIAN TRUNG BINH (ms)")
print(trung_binh.to_string())
print()
print("BANG DO LECH CHUAN (ms)")
print(do_lech.to_string())
print()

ngau_nhien = df[df["day"] >= 3].groupby("thuat_toan")["thoi_gian_ms"].agg(["mean", "std"])
ngau_nhien = ngau_nhien.loc[thu_tu].round(2)
ngau_nhien.to_csv("results/tong_hop_day_ngau_nhien.csv", index_label="thuat_toan")
print("TRUNG BINH TREN 8 DAY NGAU NHIEN (day 3 den 10)")
print(ngau_nhien.to_string())

trung_binh.plot(kind="bar", figsize=(12, 6), width=0.8)
plt.title("Thoi gian chay trung binh theo tung day")
plt.xlabel("Day so")
plt.ylabel("Thoi gian (ms)")
plt.xticks(rotation=0)
plt.legend(title="Thuat toan")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig("results/bieu_do_theo_day.png", dpi=200)
plt.close()

plt.figure(figsize=(8, 5))
plt.bar(ngau_nhien.index, ngau_nhien["mean"], yerr=ngau_nhien["std"], capsize=6,
        color=["#4C72B0", "#C44E52", "#55A868", "#8172B2"])
plt.title("Thoi gian trung binh tren 8 day ngau nhien")
plt.xlabel("Thuat toan")
plt.ylabel("Thoi gian (ms)")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig("results/bieu_do_ngau_nhien.png", dpi=200)
plt.close()

mau = {"QuickSort": "#4C72B0", "HeapSort": "#C44E52", "MergeSort": "#55A868", "std::sort": "#8172B2"}
trung_binh.plot(kind="line", marker="o", figsize=(10, 5), color=[mau[t] for t in thu_tu])
plt.title("Thoi gian chay theo day (duong)")
plt.xlabel("Day so")
plt.ylabel("Thoi gian (ms)")
plt.xticks(range(1, 11))
plt.legend(title="Thuat toan")
plt.grid(linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig("results/bieu_do_duong.png", dpi=200)
plt.close()

print()
print("Da luu bieu do vao thu muc results")