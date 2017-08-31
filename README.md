# netfilter_test


Through the FQUEU function of iptables, we check the url of the packet in the queue and implement drop process.


## Practice environment

- Kali amd x64
- iptables
- libpcap
- libnetfilter

## Pre-work

need lib pcap, netfilter

```
apt install libpcap-dev
apt install libmnl-dev libnfnetlink-dev libnetfilter-queue-dev
```

## Command 

- iptables setting
```
iptables -A OUTPUT -j NFQUEUE
```


- compile
```
make
```
- clean complied file
```
make clean
```
- run
```
./netfilter_test
```


## reference

- hashmap sourcode
https://github.com/rxi/map    
