import os

# Define the FIFO (Named Pipe) path
fifo_path = "/tmp/myfifo"

# Ensure the FIFO exists
if not os.path.exists(fifo_path):
    os.mkfifo(fifo_path)

print(f"Reading from FIFO: {fifo_path}")

# Open FIFO for reading
with open(fifo_path, "r") as fifo:
    while True:
        line = fifo.readline().strip()
        if not line:
            continue
        print(f"Received: {line}")
