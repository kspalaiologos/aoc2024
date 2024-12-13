import os
import re
import subprocess
import matplotlib.pyplot as plt
import zlib
def get_average_runtime(executable_path):
  runtimes = []
  for _ in range(10):
    output = subprocess.run(['./' + executable_path], capture_output=True).stdout.decode()
    runtime = float(re.search(r'Elapsed: ([0-9.]+) s', output).group(1))
    runtimes.append(runtime)
  return (sum(runtimes) / len(runtimes)) * 1000
def sema_density(file_path):
  with open(file_path, 'rb') as f:
    return len(zlib.compress(f.read()))
files = os.listdir()
c_files = [f for f in files if re.match(r'd[0-9]+.c', f)]
out_files = [f for f in files if re.match(r'd[0-9]+.out', f)]
c_files.sort(); out_files.sort()
ids = [int(re.match(r'd([0-9]+)\.', f).group(1)) for f in c_files]
c_file_sizes = [os.path.getsize(f) for f in c_files]
sema_densities = [sema_density(f) for f in c_files]
out_file_runtimes = [get_average_runtime(f) for f in out_files]
plt.figure()
fig, ax1 = plt.subplots()
ax2 = ax1.twinx()
ax1.plot(ids, c_file_sizes, label='C File Size (bytes)', color='tab:blue')
ax1.plot(ids, sema_densities, label='C Semantic Density (bytes)', color='tab:red')
ax1.set_xlabel('Day')
ax1.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'{x:.0f} B'))
ax1.set_ylim([250, 1000])
ax1.legend(loc='upper left')
ax1.grid(True)
ax1.yaxis.set_major_locator(plt.MultipleLocator(50))
ax2.plot(ids, out_file_runtimes, label='Average Runtime (ms)', color='tab:orange')
ax2.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'{x:.0f} ms'))
ax2.set_ylim([0, 150])
ax2.legend(loc='upper right')
plt.title("Advent of Code 2024")
plt.xticks(ids)
plt.tight_layout()
plt.savefig('bench.png')
plt.close()
print("Benchmarking complete. Results saved to bench.png")

