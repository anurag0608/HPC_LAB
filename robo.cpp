#include <stdio.h>
#include <mpi.h>
  #include <time.h>

#include <stdlib.h>
// 1 0 1 1 1 1 0 0 0 0 1  sum 6
int main(int argc, char *argv[])
{
  
  int rank, size, break_point, prob[100],value[100],from,to,num=0;
  for (int i = 0; i < 100; ++i)
  {
    /* code */
    num = rand() % 2;
    prob[i]=num;
  }
  
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
//   0-100 arr  100/4
//     25             0
//     26-50 1
//     51
  /*MPI_Scatter(
    void* send_data,
    int send_count,
    MPI_Datatype send_datatype,
    void* recv_data,
    int recv_count,
    MPI_Datatype recv_datatype,
    int root,
    MPI_Comm communicator)*/

  //from = rank*100/size;
  //to= (rank+1)*100/size;

  MPI_Scatter(prob, 100/size,MPI_INT,value,100/size,MPI_INT,0,MPI_COMM_WORLD);

  int count = 0;
  
  for(int i=0; i<100/size;i++)
  {
    if(value[i]==1)
      count++;
  }
  printf("process %d has picked %d mangoes\n", rank, count);
// MPI_Reduce(
//     void* send_data,
//     void* recv_data,
//     int count,
//     MPI_Datatype datatype,
//     MPI_Op op,
//     int root,
//     MPI_Comm communicator)
  MPI_Reduce(&count,&break_point,1,MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if(rank ==0)
  	printf("total sum is %d\n",break_point);
  MPI_Finalize();
  return 0;
}