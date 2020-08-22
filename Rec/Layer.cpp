#include "Layer.h"
#include <vector>
#include <iostream>

namespace ReconLib{

    int mulMatriz(Matriz m, Matriz f){
        int res = 0;
        for(int i=0;i<m.ancho;i++){
            for(int j=0;j<m.alto;j++){
                res+=m.get(i,j)*f.get(i,j);
                //std::cout<<"i: "<<i<<" j: "<<j<<" res: "<<res<<'\n';
            }
        }
        return res;
    }

    Matriz subMatriz(Matriz m,int i, int j, int kernel){
        Matriz sub(kernel);
        for(int x=0;x<kernel;x++){
            for(int y=0;y<kernel;y++){
                sub.set(x,y,m.get(i+x,j+y));
            }
        }
        return sub;
    }

    void Layer::setFilters(){
        Matriz fil1(3,3); //bottom border
        Matriz fil2(3,3); //right border
        Matriz fil3(3,3); //top border
        Matriz fil4(3,3); //lefth border

        fil1.set(0,0,-1);
        fil1.set(0,1,-1);
        fil1.set(0,2,-1);
        fil1.set(1,0,1);
        fil1.set(1,1,1);
        fil1.set(1,2,1);
        fil1.set(2,0,0);
        fil1.set(2,1,0);
        fil1.set(2,2,0);

        fil2.set(0,0,-1);
        fil2.set(0,1,1);
        fil2.set(0,2,0);
        fil2.set(1,0,-1);
        fil2.set(1,1,1);
        fil2.set(1,2,0);
        fil2.set(2,0,-1);
        fil2.set(2,1,1);
        fil2.set(2,2,0);

        fil3.set(0,0,0);
        fil3.set(0,1,0);
        fil3.set(0,2,0);
        fil3.set(1,0,1);
        fil3.set(1,1,1);
        fil3.set(1,2,1);
        fil3.set(2,0,-1);
        fil3.set(2,1,-1);
        fil3.set(2,2,-1);

        fil4.set(0,0,0);
        fil4.set(0,1,1);
        fil4.set(0,2,-1);
        fil4.set(1,0,0);
        fil4.set(1,1,1);
        fil4.set(1,2,-1);
        fil4.set(2,0,0);
        fil4.set(2,1,1);
        fil4.set(2,2,-1);

        this->filters.push_back(fil1);
        this->filters.push_back(fil2);
        this->filters.push_back(fil3);
        this->filters.push_back(fil4);
        // this->filters.at(0).mostrar();
        // this->filters.at(1).mostrar();
        // this->filters.at(2).mostrar();
        // this->filters.at(3).mostrar();
    }

    std::vector<Matriz> Layer::convolution(int fill_num, Matriz m){
        std::vector<Matriz> convLayer;
        int contador = 0;
        for(Matriz fil:this->filters){
            if(contador<fill_num){
                fil.mostrar();
                Matriz mf(m.ancho-(fil.ancho-1),m.alto-(fil.alto-1));
                std::cout<<"ancho mf: "<< mf.ancho << "alto mf: "<< mf.alto;
                //int o = mulMatriz(m,fil);
                for(int j=0;j<mf.alto;j++){
                    for(int i=0;i<mf.ancho;i++){
                        Matriz mi=subMatriz(m,i,j,fil.ancho);
                        mf.set(i,j,mulMatriz(mi,fil));
                    }
                }
                std::cout<<"El resultado del filtro es: "<<'\n';
                //mf.mostrar();
                std::cout<<'\n';
                convLayer.push_back(mf);
            }
            else{
                break;
            }
            contador++;
        }
        return convLayer;
    }

	Matriz Layer::maxpooling(std::vector<std::vector<int>> matrix){

    }
	// std::vector<std::vector<int>> Layer::flatten(std::vector<Matriz> vector_matrix){
    //     return NULL;
    // }
	// int ReLu(int ReLu);
	// Matriz optimize(int label_num,Matriz matrix,int ages);
}