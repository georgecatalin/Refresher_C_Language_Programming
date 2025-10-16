# Interprocess Communication (IPC)

In C programming, **Interprocess Communication (IPC)** refers to various methods for processes to communicate and synchronize with each other. Here are the main IPC techniques in C, along with their pros, cons, and suitable scenarios:

---

### 1. **Pipes**
#### **Types:** 
- **Unnamed Pipes:** Only for related processes (parent-child).
- **Named Pipes (FIFOs):** For unrelated processes.

#### **How it Works:**  
- Data is written to one end and read from the other (byte stream).
- Unnamed pipes are created using `pipe()`.
- Named pipes are created using `mkfifo()`.

#### **Pros:**
- Simple to use.
- Good for linear data flow.

#### **Cons:**
- Unnamed pipes: Only between related processes.
- Unidirectional (must create two for bidirectional).
- No random access (stream, not packet).

#### **Suitable Scenarios:**
- Parent-child communication, e.g., shell piping commands.
- Simple data transfer needs.

---

### 2. **Message Queues**
#### **How it Works:**  
- Messages are sent/received via a queue (identified by a key).
- Functions: `msgget()`, `msgsnd()`, `msgrcv()`.

#### **Pros:**
- Can communicate between unrelated processes.
- Messages can have type, allowing selective reception.
- Asynchronous communication.

#### **Cons:**
- Limited message size.
- Kernel resource limits.
- More complex than pipes.

#### **Suitable Scenarios:**
- When processes need to send discrete packets of data.
- Unrelated processes exchanging commands or status.

---

### 3. **Shared Memory**
#### **How it Works:**  
- Area of memory mapped into address space of multiple processes.
- Functions: `shmget()`, `shmat()`, `shmdt()`.

#### **Pros:**
- Fastest IPC (direct memory access).
- Large data transfer possible.

#### **Cons:**
- Synchronization is required (e.g., semaphores).
- Risk of race conditions or data corruption.

#### **Suitable Scenarios:**
- High-speed, large data exchange.
- Example: multimedia processing, databases.

---

### 4. **Semaphores**
#### **How it Works:**  
- Used for synchronization, not direct data transfer.
- Functions: `semget()`, `semop()`, `semctl()`.

#### **Pros:**
- Manages access to shared resources.
- Prevents race conditions.

#### **Cons:**
- No data transfer.
- Can cause deadlocks if not used properly.

#### **Suitable Scenarios:**
- Synchronizing access to shared memory.
- Resource management (e.g., controlling access to files).

---

### 5. **Signals**
#### **How it Works:**  
- Notification mechanism (software interrupts).
- Functions: `kill()`, `signal()`, `sigaction()`.

#### **Pros:**
- Simple notification.
- Works system-wide.

#### **Cons:**
- Only delivers small integer value.
- Not for data transfer.
- Asynchronous; can be missed.

#### **Suitable Scenarios:**
- Alerting processes of events (e.g., child termination).

---

### 6. **Sockets**
#### **How it Works:**  
- Network endpoints; can be used for IPC on local machine or over network.
- Functions: `socket()`, `bind()`, `listen()`, `accept()`, `connect()`.

#### **Pros:**
- Can communicate locally or over network.
- Supports stream (TCP) or datagram (UDP).

#### **Cons:**
- More complex setup.
- Overhead compared to shared memory.

#### **Suitable Scenarios:**
- Client-server applications.
- Communication between processes on different machines.

---

## **Summary Table**

| Technique         | Pros                    | Cons                | Suitable For                   |
|-------------------|-------------------------|---------------------|-------------------------------|
| Pipes             | Simple; fast            | Related proc only; unidirectional | Parent-child, shell scripts  |
| Message Queues    | Flexible; async         | Kernel limits; complex | Command/status exchange       |
| Shared Memory     | Fast; large data        | Needs sync; risk of race | Large, fast data exchange     |
| Semaphores        | Sync control            | No data transfer; deadlocks | Access management            |
| Signals           | Simple notification     | Limited info; async   | Event alerts                  |
| Sockets           | Network capable         | Complex; overhead    | Client-server, distributed    |

---

## **Choosing a Technique**

- **Simple data flow between related processes:** Pipes.
- **Unrelated processes, discrete messages:** Message Queues.
- **Large/fast data exchange:** Shared Memory (with Semaphores).
- **Synchronization only:** Semaphores.
- **Event notification:** Signals.
- **Network/distributed communication:** Sockets.

If you need code examples or deeper technical details for any method, let me know!