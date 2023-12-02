//
// Created by signal on 12/2/23.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void Draw() = 0;
};
#endif //DRAWABLE_H
