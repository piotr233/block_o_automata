//
// Created by pc on 04.05.2021.
//

#ifndef BLOCK_O_AUTOMATA_EMPTY_CELL_H
#define BLOCK_O_AUTOMATA_EMPTY_CELL_H
#include "cell.h"

class empty_cell: public cell{

public:
    empty_cell();
    empty_cell( bool locked);

    type getCellType() const override;

    empty_cell &operator=(const empty_cell &other)  = default;

    void action(const std::vector<cell *> &plane, unsigned w, coord curr_pos, std::vector<cell *> &destination) override;

    void move(const std::vector<cell *> &plane, std::vector<cell *> &destination, direction move_dir, coord curr_pos,
              unsigned int width) override;

    icon get_unicode() override;

    bool isLocked() const;

    void rotateRight()  noexcept override{};

    void setLocked(bool locked);

    bool operator==(const type& rhs) const override;

    bool operator!=(const type &rhs) const override;

    void output_fo_file(std::ostream &out) override;

    static type cell_type ;

    empty_cell* clone() override;

protected:
    /// can player put cells in place this one
    bool locked;
};


#endif //BLOCK_O_AUTOMATA_EMPTY_CELL_H
