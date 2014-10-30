#pragma once

#include <geometry/Cell.h>
#include <geometry/ChamberIterator.h>

#include <vector>
#include <memory>
#include <iostream>

/** The geometric representation of the drift chamber.
 */
class Chamber {
public:
  /** Constructor for a Chamber with a number of lines given by parameter. */
  Chamber(unsigned nLayers = 4);


  /** Prints some visualization on the command line.
   *
   *  This is one of the major functions of this programm,
   *  as the chamber "knows" as well about its energy depostion.
   */
  void visualize() const;

  /** Returns an iterator connected to the first Cell.
   *
   *  You can use this iterator to loop over all Cells of the Chamber.
   *  There is no end() function implemented, but an interator will return a
   *  nullptr, if it is iterated over the last element.
   */
  ChamberIterator first() const;

  /** This is a very preliminary way of adding cells.
   *
   *  The reason is, that one big task for the project is to write
   *  a new representation for the Chamber.
   */
  void addCell();

  /** "Empties" all cells by resetting their energy deposition.
   *
   *  This function is used as well in the GeometryCreator.
   */
  void cleanUp();

  /** A shared pointer to the cell at the given position is returned.
   *
   *  This is probably needed for the ParticleGun.
   *  Note: A shared pointer acts mostly like a pointer, that has ownership of the thing!
   *  See: http://www.cplusplus.com/reference/memory/shared_ptr/?kw=shared_ptr
   */
  std::shared_ptr<Cell> getCellAt(unsigned xPosition, unsigned yPosition) const;

  /** Returns the maximum x-value, that is covered by the Chamber. */
  unsigned getMaxX() const {
    return (m_cells[0].size());
  }

  /** Returns the maximum y-value, that is covered by the Chamber. */
  unsigned getMaxY() const {
    return m_cells.size();
  }

private:
  std::vector< std::vector<std::shared_ptr<Cell> > > m_cells;
};
