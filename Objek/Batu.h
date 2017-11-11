#ifndef BATU_H
#define BATU_H

#include "../Util/Util.h"
#include "GL/glut.h"
#include <vector>
#include <iostream>

using namespace std;

float verticesBatu1[][10][3] = {
    {
        {-0.276388, -0.955261, -0.315154},
        {-0.858745, -0.604609, -0.315154},
        {-1.16508, 0.006849, -0.36948},
        {-0.787149, 0.484953, -0.35881},
        {-0.276389, 0.746036, -0.315152},
        {0.262867, 0.7044, -0.315152},
        {0.723608, 0.421114, -0.315152},
        {0.924464, -0.104611, -0.307173},
        {0.799278, -0.630337, -0.306974},
        {0.262867, -0.913623, -0.315152}, 
    },
    // Level 1
    {
        {-0.276388, -0.955261, -0.315154},
        {-0.08152, -1.10461, -0.029731},
        {-0.793031, -0.913628, -0.029732},
    },
    {
        {-0.793031, -0.913628, -0.029732},
        {-0.276388, -0.955261, -0.315154},
        {-0.858745, -0.604609, -0.315154}
    },
    {
        {-0.858745, -0.604609, -0.315154},
        {-0.793031, -0.913628, -0.029732},
        {-1.23953, -0.367864, -0.022304}        
    },
    {
        {-0.858745, -0.604609, -0.315154},
        {-1.23953, -0.367864, -0.022304},
        {-1.16508, 0.006848, -0.36948}        
    },
    {
        {-1.23953, -0.367864, -0.022304},
        {-1.16508, 0.006848, -0.36948},
        {-1.26781, 0.418119, -0.104168}     
    },
    {
        {-1.26781, 0.418119, -0.104168},
        {-1.16508, 0.006848, -0.36948},
        {-0.787149, 0.484953, -0.35881}        
    },
    {
        {-0.787149, 0.484953, -0.35881},
        {-1.26781, 0.418119, -0.104168},
        {-0.622365, 0.832534, -0.018049}     
    },
    {
        {-0.622365, 0.832534, -0.018049},
        {-0.787149, 0.484953, -0.35881},
        {-0.276389, 0.746036, -0.315152}        
    },
    {
        {-0.276389, 0.746036, -0.315152},
        {-0.622365, 0.832534, -0.018049},
        {0.007997, 0.967786, -0.00005}
    },
    {
        {0.007997, 0.967786, -0.00005},
        {-0.276389, 0.746036, -0.315152},
        {0.262867, 0.7044, -0.315152}        
    },
    {
        {0.262867, 0.7044, -0.315152},
        {0.007997, 0.967786, -0.00005},
        {0.587786, 0.704405, 0}        
    },
    {
        {0.262867, 0.7044, -0.315152},
        {0.723608, 0.421114, -0.315152},        
        {0.587786, 0.704405, 0}        
    },
    {
        {0.587786, 0.704405, 0},
        {0.723608, 0.421114, -0.315152},
        {1.07007, 0.199058, 0.033483}        
    },
    {
        {1.07007, 0.199058, 0.033483},
        {0.723608, 0.421114, -0.315152},
        {0.924464, -0.104611, -0.307173}        
    },
    {
        {1.07007, 0.199058, 0.033483},
        {0.924464, -0.104611, -0.307173},
        {1.1716, -0.418732, 0.044205}
    },
    {
        {0.924464, -0.104611, -0.307173},
        {1.1716, -0.418732, 0.044205},
        {0.799278, -0.630337, -0.306974}        
    },
    {
        {1.1716, -0.418732, 0.044205},
        {0.799278, -0.630337, -0.306974},
        {0.623272, -0.913628, 0.003836}
    },
    {
        {0.799278, -0.630337, -0.306974},
        {0.623272, -0.913628, 0.003836},
        {0.262867, -0.913623, -0.315152}        
    },
    {
        {0.623272, -0.913628, 0.003836},
        {0.262867, -0.913623, -0.315152},
        {-0.08152, -1.10461, -0.029731}
    },
    {
        {-0.08152, -1.10461, -0.029731},
        {-0.276388, -0.955261, -0.315154},
        {0.262867, -0.913623, -0.315152}        
    },
    // Level 2
    {
        {-0.08152, -1.10461, -0.029731},
        {0.158321, -0.955261, 0.443813},
        {-0.606447, -0.913623, 0.402813}    
    },
    {
        {-0.606447, -0.913623, 0.402813},
        {-0.08152, -1.10461, -0.029731},
        {-0.793031, -0.913628, -0.029732}        
    },
    {
        {-0.793031, -0.913628, -0.029732},
        {-0.606447, -0.913623, 0.402813},
        {-0.987689, -0.630337, 0.40416}        
    },
    {
        {-0.987689, -0.630337, 0.40416},
        {-0.793031, -0.913628, -0.029732},
        {-1.23953, -0.367864, -0.022304},       
    },
    {
        {-1.23953, -0.367864, -0.022304},       
        {-0.987689, -0.630337, 0.40416},
        {-0.999035, -0.052439, 0.500306}        
    },
    {
        {-0.999035, -0.052439, 0.500306},
        {-1.26781, 0.418119, -0.104168},
        {-0.782686, 0.638765, 0.416836}        
    },
    {
        {-0.999035, -0.052439, 0.500306},
        {-1.26781, 0.418119, -0.104168},
        {-1.23953, -0.367864, -0.022304}        
    },
    {
        {-0.782686, 0.638765, 0.416836},
        {-1.26781, 0.418119, -0.104168},
        {-0.622365, 0.832534, -0.018049}        
    },
    {
        {-0.782686, 0.638765, 0.416836},
        {-0.622365, 0.832534, -0.018049},
        {-0.229807, 1.00137, 0.525532}
    },
    {
        {-0.229807, 1.00137, 0.525532},
        {-0.622365, 0.832534, -0.018049},
        {0.007997, 0.967786, -0.00005}        
    },
    {
        {0.007997, 0.967786, -0.00005},
        {-0.229807, 1.00137, 0.525532},
        {0.28797, 0.875144, 0.447148}        
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.007997, 0.967786, -0.00005},
        {0.587786, 0.704405, 0}        
    },
    {
        {0.587786, 0.704405, 0},
        {1.07007, 0.199058, 0.033483},
        {0.770812, 0.390536, 0.552645}  
    },
    {
        {0.770812, 0.390536, 0.552645},
        {1.07007, 0.199058, 0.033483},
        {1.15686, -0.119863, 0.537402}
    },
    {
        {1.15686, -0.119863, 0.537402},
        {1.1716, -0.418732, 0.044205},
        {0.808181, -0.609808, 0.558422}     
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.770812, 0.390536, 0.552645},
        {0.587786, 0.704405, 0}        
    },
    {
        {0.808181, -0.609808, 0.558422},
        {0.623272, -0.913628, 0.003836},
        {0.158321, -0.955261, 0.443813}       
    },
    {
        {0.158321, -0.955261, 0.443813},
        {-0.08152, -1.10461, -0.029731},
        {-0.606447, -0.913623, 0.402813}        
    },
    {
        {0.158321, -0.955261, 0.443813},
        {-0.08152, -1.10461, -0.029731},
        {0.623272, -0.913628, 0.003836}        
    },
    {
        {0.623272, -0.913628, 0.003836},
        {0.808181, -0.609808, 0.558422},       
        {1.1716, -0.418732, 0.044205}        
    },
    {
        {1.1716, -0.418732, 0.044205},
        {1.15686, -0.119863, 0.537402},
        {1.07007, 0.199058, 0.033483}        
    },
    // Level 3
    {
        {0.158321, -0.955261, 0.443813},
        {0.808181, -0.609808, 0.558422},               
        {0.116779, -0.703853, 0.876573}        
    },
    {
        {0.158321, -0.955261, 0.443813},
        {0.116779, -0.703853, 0.876573},        
        {-0.606447, -0.913623, 0.402813}
    },
    {
        {0.116779, -0.703853, 0.876573},        
        {-0.606447, -0.913623, 0.402813},
        {-0.483381, -0.478594, 0.798076}         
    },
    {
        {-0.483381, -0.478594, 0.798076},         
        {-0.606447, -0.913623, 0.402813},
        {-0.987689, -0.630337, 0.40416}
    },
    {
        {-0.987689, -0.630337, 0.40416},
        {-0.483381, -0.478594, 0.798076},         
        {-0.999035, -0.052439, 0.500306}
    },
    {
        {-0.483381, -0.478594, 0.798076},         
        {-0.999035, -0.052439, 0.500306},
        {-0.394696, 0.274832, 0.757868}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.999035, -0.052439, 0.500306},
        {-0.782686, 0.638765, 0.416836}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.782686, 0.638765, 0.416836},
        {-0.229807, 1.00137, 0.525532}        
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.229807, 1.00137, 0.525532},
        {0.186989, 0.482376, 0.779228}
    },
    {
        {-0.229807, 1.00137, 0.525532},
        {0.28797, 0.875144, 0.447148},
        {0.186989, 0.482376, 0.779228}        
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.186989, 0.482376, 0.779228},       
        {0.770812, 0.390536, 0.552645}
    },
    {
        {0.186989, 0.482376, 0.779228},       
        {0.770812, 0.390536, 0.552645},
        {0.650486, -0.205198, 0.856856}
    },
    {
        {0.770812, 0.390536, 0.552645},
        {0.650486, -0.205198, 0.856856},
        {1.15686, -0.119863, 0.537402}
    },
    {
        {1.15686, -0.119863, 0.537402},
        {0.650486, -0.205198, 0.856856},
        {0.808181, -0.609808, 0.558422}        
    },
    {
        {0.650486, -0.205198, 0.856856},
        {0.808181, -0.609808, 0.558422},        
        {0.116779, -0.703853, 0.876573}
    },
    //Level 4
    {
        {-0.394696, 0.274832, 0.757868},        
        {-0.483381, -0.478594, 0.798076},
        {0.117802, -0.206886, 0.98599}
    },
    {
        {-0.394696, 0.274832, 0.757868},        
        {0.117802, -0.206886, 0.98599},
        {0.186989, 0.482376, 0.779228}        
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.186989, 0.482376, 0.779228},
        {0.650486, -0.205198, 0.856856}              
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.650486, -0.205198, 0.856856},
        {0.116779, -0.703853, 0.876573}        
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.116779, -0.703853, 0.876573},
        {-0.483381, -0.478594, 0.798076}        
    }
};

void batu() {
    glPushMatrix();
        glColor3ub(120, 120, 120);
        glTranslatef(0, 0.3, 0);
        glRotatef(-90, 1, 0, 0);
        for (int i = 0; i < 62 ; i++) {
            glBegin(GL_POLYGON);
            for(float *point : verticesBatu1[i]) {
                glNormal3f(*point, *(point + 1), *(point + 2));    
                glVertex3f(*point, *(point + 1), *(point + 2));   
            }
            glEnd();
        }
    glPopMatrix();
}

#endif