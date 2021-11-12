from mpi4py import MPI
import random

if __name__ == "__main__":
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    meet_lst = list(range(1, size))
    name = 'processor_'+ str(rank)
    if rank == 0:
        met = [rank]
        destination = random.choice(meet_lst)
        message = name
        comm.ssend([message, met], dest=destination, tag=0)
    else:
        message, met = comm.recv()
        message += ' ' + name
        print('message:', message)
        print('already met:', met)
        met.append(rank)
        meet_lst = list(set(meet_lst) - set(met))
        if len(meet_lst) > 0:
            destination = random.choice(meet_lst)
            comm.ssend([message, met], dest=destination, tag=rank)
    MPI.Finalize()
