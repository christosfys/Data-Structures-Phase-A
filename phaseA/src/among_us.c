/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Antonios Peris                         *
 * @Version 20-10-2020                             *
 * @email   csdp1196@csd.uoc.gr                    *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

#include "among_us.h"

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
    players_head=(struct Players*)malloc(sizeof(struct Players));
    players_head->next=players_head;
    players_head->prev=players_head;
    players_head->evidence=-1;
    players_head->is_alien=-1;
    players_head->pid=-1;
    players_head->tasks_head=(struct Tasks*)malloc(sizeof(struct Tasks));
    players_head->tasks_head=NULL;
    players_head->tasks_sentinel=(struct Tasks*)malloc(sizeof(struct Tasks));
    players_head->tasks_sentinel=NULL;

   //players_head->tasks_sentinel->next=players_head->tasks_sentinel;



    /* players_head->tasks_head=players_head;
    players_head->tasks_sentinel=players_head;*/


	     tasks_head=(struct Head_GL*)malloc(sizeof(struct Head_GL));
//	    tasks_head->head=(struct Tasks*)malloc(sizeof(struct Tasks));
	
    	 tasks_head->head=NULL;

  		 tasks_head->tasks_count[0]=0;
    	 tasks_head->tasks_count[2]=0;
    	 tasks_head->tasks_count[1]=0;


    return 1;
}

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid,int is_alien) {
    struct Players *head=players_head;
    struct Players *tmphead=players_head;
	head=players_head->next;
    while (head->next!=tmphead)
    {
        head=head->next;
    }
    struct Players *new=(struct Players*)malloc(sizeof(struct Players));
    head->next=new;
    new->next=tmphead;
    new->prev=head;

    tmphead->prev=new;
    
    new->pid=pid;
    new->is_alien=is_alien;
    new->tasks_head=(struct Tasks*)malloc(sizeof(struct Tasks));
    new->tasks_sentinel=(struct Tasks*)malloc(sizeof(struct Tasks));
    new->tasks_head=players_head->tasks_sentinel;
    new->tasks_sentinel->tid=-1;
    new->tasks_sentinel->difficulty=0;
    new->tasks_sentinel->next=NULL;
	 struct Players *temphead=players_head;
	temphead=temphead->next;

    printf("P <pid><is_alien>\n Players=");
    while (temphead!=tmphead)
    {
//        temphead=temphead->next;
  
      printf("<%d:%d>,",temphead->pid,temphead->is_alien);
	temphead=temphead->next;

    }
    printf("\nDONE\n");
    return 1;
}

/**
 * @brief Insert task in the general task list
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid,int difficulty) {

    
    struct Tasks *p;
    tasks_head->tasks_count[difficulty-1]++;
  
    if(tasks_head->head==NULL){
     struct Tasks *new;
     new =(struct Tasks*)malloc(sizeof(struct Tasks));
    new->tid=tid;
	new->difficulty=difficulty;	
	new->next=NULL;
    tasks_head->head=new;
    }else{

    

	p=tasks_head->head;
	struct Tasks *new;
    	new =(struct Tasks*)malloc(sizeof(struct Tasks));
	    new->tid=tid;
	new->difficulty=difficulty;	
	new->next=NULL;
	struct Tasks  *p2=NULL;
    while (p!=NULL && p->difficulty <=new->difficulty)
    {
  	 p2=p;
	p=p->next;

	
    	}
        
    if(p2!=NULL){
    p2->next=new;
	new->next=p;
        }else{
            new->next=p;
            tasks_head->head=new;
            
        }
    }
    
    struct Tasks *p1;
	p1=tasks_head->head;
    printf("T <tid><difficulty> \n  Tasks:");


	while (p1!=NULL)
    {
  	printf("<%d,%d>,",p1->tid, p1->difficulty);
	    p1=p1->next;
    }
	printf("\nDONE\n")  ;  
    return 1;
}

/**
 * @brief Distribute tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {
    struct Tasks *p;
    p=tasks_head->head;
    struct Players *head=players_head;
	struct Players *t1mp=players_head->next;
    struct Tasks *shead=t1mp->tasks_head;
    struct Tasks *sentinel=t1mp->tasks_sentinel;
    while (p!=NULL)
    {
        if (t1mp->is_alien!=1 && t1mp->is_alien!=-1)
        {
                ///   printf("POUSTIS ,%d \n" , t1mp->pid);
                if(shead!=sentinel)
                {
                    struct Tasks *newTask;
                    newTask=(struct Tasks*)malloc(sizeof(struct Tasks));
                    newTask->difficulty=p->difficulty;
                    newTask->tid=p->tid;
	//           newTask->next=shead->next;
                    shead->next=newTask;
                    newTask->next=sentinel;
                    sentinel->next=newTask;
                    printf("Task number<%d,%d>\n", newTask->tid, newTask->difficulty);
                }
                
        
        }

        
        p=p->next;
        t1mp=t1mp->next;
    }
    
     

   /* if (t1mp->is_alien!=1 && t1mp->is_alien!=-1)
    {
      //  printf("skata\n");
        if (t1mp->tasks_head==t1mp->tasks_sentinel)
        {     printf("skata\n");
            struct Tasks *new=(struct Tasks*)malloc(sizeof(struct Tasks));
            new->difficulty=p->difficulty;
            new->tid=p->tid;
            new->next=t1mp->tasks_sentinel;
            t1mp->tasks_head->next=new;
            t1mp->tasks_sentinel->next=new;

        }
        
    }*/
    

   
    
   

 //  struct Players *head=players_head;
   struct Players *temp2=players_head->next;
   struct Tasks *tmp=temp2->tasks_head;
    printf("D\n");
    while (temp2->next!=head)
    
    {   	
        //temp2=temp2->next;
        printf("\nPlayer%d =",temp2->pid);
          temp2=temp2->next;

        tmp=temp2->tasks_head;
        while (tmp!=NULL)
        {
            //tmp=tmp->next;
            printf("<%d,%d>,",tmp->tid,tmp->difficulty);
            tmp=tmp->next;
        }
        
    }
    
   	printf("\nDONE\n");  
   


      
        

    return 1;
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty) {
    return 1;
}

/**
 * @brief Eject Player
 * 
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid) {
    return 1;
}

/**
 * @brief Witness Eject Player
 *
 * @param pid_a The alien's pid
 * 
 * @param pid The crewmate's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid, int pid_a, int number_of_witnesses){
    return 1;
}


/**
 * @brief Sabbotage
 *
 * @param pid The player's id
 *
 * @param number_of_tasks The number of tasks to be popped
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabbotage(int pid, int number_of_tasks) {
    return 1;
}


/**
 * @brief Vote
 *
 * @param pid The player's id
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid, int vote_evidence) {
    return 1;
}


/**
 * @brief Give Away Work
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work() {
    return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
    return 1;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
        struct Players *tmphead=players_head;
    	 struct Players *temphead=players_head;
	temphead=temphead->next;

    printf("X <pid><is_alien>\n Players=");
    while (temphead!=tmphead)
    {
//        temphead=temphead->next;
  
      printf("<%d:%d>,",temphead->pid,temphead->is_alien);
	temphead=temphead->next;

    }
    printf("\nDONE\n");
    return 1;
}

  
/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
       
    struct Tasks *p1;
	p1=tasks_head->head;
    printf("Y <tid><difficulty> \n  Tasks:");


	while (p1!=NULL)
    {
//	p1=p1->next;
  	printf("<%d,%d>,",p1->tid, p1->difficulty);
	    p1=p1->next;
//	printf("%d\n",j);
    }


	printf("\nDONE\n")  ;  
    return 1;
}

/**
 * @brief Print Stack
 *
 * @return 1 on success
 *         0 on failure
 */
int print_stack() {
    return 1;
}

/**
 * @brief Print Players & Task List
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_list() {
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void) {
    return 1;
}
/*   if(head->pid!=1 && head->pid!=-1){
            if(head->tasks_head==head->tasks_sentinel->next){
                struct Tasks *new;
              
                )
                new=p;
                head->tasks_head=new;
                p=p->next;
                new->next=head->tasks_sentinel;
                head->tasks_sentinel->next=new;
                new->next=head->tasks_sentinel;
            } else
            {
                struct Tasks *new;
                struct Tasks *tmp;
                tmp=(struct Tasks*)malloc(sizeof(struct Tasks));
                new=(struct Tasks*)malloc(sizeof(struct Tasks));
                new=head->tasks_sentinel->next;
                tmp=new;
                head->tasks_sentinel->next=new;
                new=p;
                tmp->next=new;
                p=p->next;
            }
            
            head=head->next;
        }else
        {
            head=head->next;
        }    */
   // }

   

   /**
    * struct Tasks *newhead=(struct Tasks*)malloc(sizeof(struct Tasks));
    new->tasks_head=newhead;
    struct Tasks *newsen=(struct Tasks*)malloc(sizeof(struct Tasks));
    new->tasks_sentinel=newsen;

  //  new->tasks_head=(struct Tasks*)malloc(sizeof(struct Tasks));
     new->tasks_sentinel=(struct Tasks*)malloc(sizeof(struct Tasks));
     newhead=newsen;
    newsen->tid=-1;
    newsen->difficulty=0;
  //  new->tasks_sentinel->next=NULL;
    * */
