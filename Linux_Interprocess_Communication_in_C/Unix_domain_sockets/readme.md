# Unix Domain Sockets

## What are Unix Domain Sockets?

Unix Domain Sockets are a way for two programs (processes) running on the same computer to exchange data, like sending messages back and forth.  
Think of it like a phone line between two apps, but only inside your computer.

- **Local only:** They do not use the network, just your computer’s filesystem.
- **Bidirectional:** Both programs can send and receive.
- **Unrelated processes:** Programs don’t have to be parent-child.

---
