# Unix Domain Sockets

## What are Unix Domain Sockets?

Unix Domain Sockets are a way for two programs (processes) running on the same computer to exchange data, like sending messages back and forth.  
Think of it like a phone line between two apps, but only inside your computer.

- **Local only:** They do not use the network, just your computer’s filesystem.
- **Bidirectional:** Both programs can send and receive.
- **Unrelated processes:** Programs don’t have to be parent-child.

---


```c name=client.c url=https://github.com/georgecatalin/Refresher_C_Language_Programming/blob/main/Linux_Interprocess_Communication_in_C/Unix_domain_sockets/client.c
client.c — A simple Unix-domain socket client. 
Purpose: demonstrates creating a socket, connecting to a local (AF_UNIX) server, sending and receiving data, basic error handling and cleanup.
Learning points: socket(), connect(), send()/write()/recv()/read(), struct sockaddr_un, path-based socket addressing, blocking client behavior, basic protocol/IO loop.
Build/run hint: gcc -Wall -Wextra client.c -o client ; run after server is listening. 
```

```c name=server.c url=https://github.com/georgecatalin/Refresher_C_Language_Programming/blob/main/Linux_Interprocess_Communication_in_C/Unix_domain_sockets/server.c
server.c — A straightforward Unix-domain socket server (single-client or sequential handling).
Purpose: shows socket creation, binding to a filesystem socket path, listen(), accept(), read/write to a client, unlinking socket file on exit, and cleanup.
Learning points: socket lifecycle, struct sockaddr_un and bind(), listen()/accept(), basic request/response loop, signal/safe cleanup considerations, permissions on socket file.
Build/run hint: gcc -Wall -Wextra server.c -o server ; run first to create the listening socket file, then start clients.
```

```c name=multiplexing_server.c url=https://github.com/georgecatalin/Refresher_C_Language_Programming/blob/main/Linux_Interprocess_Communication_in_C/Unix_domain_sockets/multiplexing_server.c
multiplexing_server.c — A more advanced server using I/O multiplexing.
Purpose: demonstrates how to handle multiple simultaneous Unix-domain client connections in a single process using an I/O multiplexing mechanism (select/poll).
Learning points: FD sets and select() (or poll), maintaining a table of client fds, updating max fd, accepting new connections while servicing existing ones, non-blocking considerations, scalable single-threaded server design, more robust error handling and resource management.
Build/run hint: gcc -Wall -Wextra multiplexing_server.c -o mserver ; run mserver and connect several clients to see concurrent handling.
```

````markdown name=readme.md url=https://github.com/georgecatalin/Refresher_C_Language_Programming/blob/main/Linux_Interprocess_Communication_in_C/Unix_domain_sockets/readme.md
readme.md — Explanatory notes for the examples in this directory.
Purpose: describes the exercises, provides compile/run instructions and explains the socket path conventions for AF_UNIX. Useful for quick orientation before running the examples.
Learning points: background context for the sample programs, expected behavior and instructions for hands-on practice.
````

### What these files teach together
- The fundamentals of Unix-domain (AF_UNIX) sockets: how local IPC uses filesystem-named sockets rather than network addresses.
- Server and client lifecycle: socket(), bind()/connect(), listen()/accept(), read()/write(), close(), and cleanup (unlinking socket file).
- Synchronous blocking IO vs. multiplexed IO: server.c shows simple sequential handling; multiplexing_server.c shows how to scale to many concurrent clients in one process.
- Practical C systems programming: working with POSIX APIs, error checking, resource cleanup, file-descriptor management, and attention to corner cases.

### Suggested next steps / exercises
- Compile and run the examples to see behavior and messages.
- Modify server to use non-blocking sockets or change multiplexing to poll() or epoll() (where applicable).
- Implement message framing (length-prefix) to handle partial reads/writes robustly.
- Add authentication/permission checks or use socket file permissions to limit access.
- Experiment with sending file descriptors (SCM_RIGHTS) over Unix sockets (advanced).
- Convert to SOCK_DGRAM (datagram) Unix sockets to learn differences in semantics.
