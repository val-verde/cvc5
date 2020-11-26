/*********************                                                        */
/*! \file floatingpoint.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Aina Niemetz, Martin Brain, Mathias Preiner
 ** Copyright (c) 2013  University of Oxford
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2020 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief A floating-point value.
 **
 ** This file contains the data structures used by the constant and parametric
 ** types of the floating point theory.
 **/
#include "cvc4_public.h"

#ifndef CVC4__FLOATINGPOINT_H
#define CVC4__FLOATINGPOINT_H

#include "util/bitvector.h"
#include "util/floatingpoint_size.h"
#include "util/rational.h"
#include "util/roundingmode.h"

/* -------------------------------------------------------------------------- */

namespace CVC4 {

/* -------------------------------------------------------------------------- */

class FloatingPointLiteral;

class CVC4_PUBLIC FloatingPoint
{
 public:
  /**
   * Wrappers to represent results of non-total functions (e.g., min/max).
   * The Boolean flag is true if the result is defined, and false otherwise.
   */
  using PartialFloatingPoint = std::pair<FloatingPoint, bool>;
  using PartialBitVector = std::pair<BitVector, bool>;
  using PartialRational = std::pair<Rational, bool>;

  /**
   * Get the number of exponent bits in the unpacked format corresponding to a
   * given packed format.  These is the unpacked counter-parts of
   * FloatingPointSize::exponentWidth().
   */
  static uint32_t getUnpackedExponentWidth(FloatingPointSize& size);
  /**
   * Get the number of exponent bits in the unpacked format corresponding to a
   * given packed format.  These is the unpacked counter-parts of
   * FloatingPointSize::significandWidth().
   */
  static uint32_t getUnpackedSignificandWidth(FloatingPointSize& size);

  /** Constructors. */
  FloatingPoint(uint32_t e, uint32_t s, const BitVector& bv);
  FloatingPoint(const FloatingPointSize& size, const BitVector& bv);
  FloatingPoint(const FloatingPointSize& fp_size,
                const FloatingPointLiteral* fpl);
  FloatingPoint(const FloatingPoint& fp);
  FloatingPoint(const FloatingPointSize& size,
                const RoundingMode& rm,
                const BitVector& bv,
                bool signedBV);
  FloatingPoint(const FloatingPointSize& size,
                const RoundingMode& rm,
                const Rational& r);
  /** Destructor. */
  ~FloatingPoint();

  /**
   * Create a FP NaN value of given size.
   * size: The FP size (format).
   */
  static FloatingPoint makeNaN(const FloatingPointSize& size);
  /**
   * Create a FP infinity value of given size.
   * size: The FP size (format).
   * sign: True for -oo, false otherwise.
   */
  static FloatingPoint makeInf(const FloatingPointSize& size, bool sign);
  /**
   * Create a FP zero value of given size.
   * size: The FP size (format).
   * sign: True for -zero, false otherwise.
   */
  static FloatingPoint makeZero(const FloatingPointSize& size, bool sign);
  /**
   * Create the smallest subnormal FP value of given size.
   * size: The FP size (format).
   * sign: True for negative sign, false otherwise.
   */
  static FloatingPoint makeMinSubnormal(const FloatingPointSize& size,
                                        bool sign);
  /**
   * Create the largest subnormal FP value of given size.
   * size: The FP size (format).
   * sign: True for negative sign, false otherwise.
   */
  static FloatingPoint makeMaxSubnormal(const FloatingPointSize& size,
                                        bool sign);
  /**
   * Create the smallest normal FP value of given size.
   * size: The FP size (format).
   * sign: True for negative sign, false otherwise.
   */
  static FloatingPoint makeMinNormal(const FloatingPointSize& size, bool sign);
  /**
   * Create the largest normal FP value of given size.
   * size: The FP size (format).
   * sign: True for negative sign, false otherwise.
   */
  static FloatingPoint makeMaxNormal(const FloatingPointSize& size, bool sign);

  /** Get the wrapped floating-point value. */
  const FloatingPointLiteral* getLiteral(void) const { return d_fpl; }

  /**
   * Return a string representation of this floating-point.
   *
   * If printAsIndexed is true then it prints the bit-vector components of the
   * FP value as indexed symbols, otherwise in binary notation.
   */
  std::string toString(bool printAsIndexed = false) const;

  /** Return the packed (IEEE-754) representation of this floating-point. */
  BitVector pack(void) const;

  /** Floating-point absolute value. */
  FloatingPoint absolute(void) const;
  /** Floating-point negation. */
  FloatingPoint negate(void) const;
  /** Floating-point addition. */
  FloatingPoint plus(const RoundingMode& rm, const FloatingPoint& arg) const;
  /** Floating-point subtraction. */
  FloatingPoint sub(const RoundingMode& rm, const FloatingPoint& arg) const;
  /** Floating-point multiplication. */
  FloatingPoint mult(const RoundingMode& rm, const FloatingPoint& arg) const;
  /** Floating-point division. */
  FloatingPoint div(const RoundingMode& rm, const FloatingPoint& arg) const;
  /** Floating-point fused multiplication and addition. */
  FloatingPoint fma(const RoundingMode& rm,
                    const FloatingPoint& arg1,
                    const FloatingPoint& arg2) const;
  /** Floating-point square root. */
  FloatingPoint sqrt(const RoundingMode& rm) const;
  /** Floating-point round to integral. */
  FloatingPoint rti(const RoundingMode& rm) const;
  /** Floating-point remainder. */
  FloatingPoint rem(const FloatingPoint& arg) const;

  /**
   * Floating-point max (total version).
   * zeroCase: true to return the left (rather than the right operand) in case
   *           of max(-0,+0) or max(+0,-0).
   */
  FloatingPoint maxTotal(const FloatingPoint& arg, bool zeroCaseLeft) const;
  /**
   * Floating-point min (total version).
   * zeroCase: true to return the left (rather than the right operand) in case
   *           of min(-0,+0) or min(+0,-0).
   */
  FloatingPoint minTotal(const FloatingPoint& arg, bool zeroCaseLeft) const;

  /**
   * Floating-point max.
   *
   * Returns a partial floating-point, which is a pair of FloatingPoint and
   * bool. The boolean flag is true if the result is defined, and false if it
   * is undefined.
   */
  PartialFloatingPoint max(const FloatingPoint& arg) const;
  /** Floating-point min.
   *
   * Returns a partial floating-point, which is a pair of FloatingPoint and
   * bool. The boolean flag is true if the result is defined, and false if it
   * is undefined.
   */
  PartialFloatingPoint min(const FloatingPoint& arg) const;

  /** Equality (NOT: fp.eq but =) over floating-point values. */
  bool operator==(const FloatingPoint& fp) const;
  /** Floating-point less or equal than. */
  bool operator<=(const FloatingPoint& arg) const;
  /** Floating-point less than. */
  bool operator<(const FloatingPoint& arg) const;

  /** Get the exponent of this floating-point value. */
  BitVector getExponent() const;
  /** Get the significand of this floating-point value. */
  BitVector getSignificand() const;
  /** True if this value is a negative value. */
  bool getSign() const;

  /** Return true if this floating-point represents a normal value. */
  bool isNormal(void) const;
  /** Return true if this floating-point represents a subnormal value. */
  bool isSubnormal(void) const;
  /** Return true if this floating-point represents a zero value. */
  bool isZero(void) const;
  /** Return true if this floating-point represents an infinite value. */
  bool isInfinite(void) const;
  /** Return true if this floating-point represents a NaN value. */
  bool isNaN(void) const;
  /** Return true if this floating-point represents a negative value. */
  bool isNegative(void) const;
  /** Return true if this floating-point represents a positive value. */
  bool isPositive(void) const;

  /**
   * Convert this floating-point to a floating-point of given size, with
   * respect to given rounding mode.
   */
  FloatingPoint convert(const FloatingPointSize& target,
                        const RoundingMode& rm) const;

  /**
   * Convert this floating-point to a bit-vector of given size, with
   * respect to given rounding mode (total version).
   * Returns given bit-vector 'undefinedCase' in the undefined case.
   */
  BitVector convertToBVTotal(BitVectorSize width,
                             const RoundingMode& rm,
                             bool signedBV,
                             BitVector undefinedCase) const;
  /**
   * Convert this floating-point to a rational, with respect to given rounding
   * mode (total version).
   * Returns given rational 'undefinedCase' in the undefined case.
   */
  Rational convertToRationalTotal(Rational undefinedCase) const;

  /**
   * Convert this floating-point to a bit-vector of given size.
   *
   * Returns a partial bit-vector, which is a pair of BitVector and bool.
   * The boolean flag is true if the result is defined, and false if it
   * is undefined.
   */
  PartialBitVector convertToBV(BitVectorSize width,
                               const RoundingMode& rm,
                               bool signedBV) const;
  /**
   * Convert this floating-point to a Rational.
   *
   * Returns a partial Rational, which is a pair of Rational and bool.
   * The boolean flag is true if the result is defined, and false if it
   * is undefined.
   */
  PartialRational convertToRational(void) const;

  /** The floating-point size of this floating-point value. */
  FloatingPointSize d_fp_size;

 private:
  /** The floating-point literal of this floating-point value. */
  FloatingPointLiteral* d_fpl;

}; /* class FloatingPoint */

/**
 * Hash function for floating-point values.
 */
struct CVC4_PUBLIC FloatingPointHashFunction
{
  size_t operator()(const FloatingPoint& fp) const
  {
    FloatingPointSizeHashFunction fpshf;
    BitVectorHashFunction bvhf;

    return fpshf(fp.d_fp_size) ^ bvhf(fp.pack());
  }
}; /* struct FloatingPointHashFunction */

/* -------------------------------------------------------------------------- */

/**
 * The parameter type for the conversions to floating point.
 */
class CVC4_PUBLIC FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointConvertSort(uint32_t _e, uint32_t _s) : d_fp_size(_e, _s) {}
  FloatingPointConvertSort(const FloatingPointSize& fps) : d_fp_size(fps) {}

  /** Operator overload for comparison of conversion sorts. */
  bool operator==(const FloatingPointConvertSort& fpcs) const
  {
    return d_fp_size == fpcs.d_fp_size;
  }

  /** The floating-point size of this sort. */
  FloatingPointSize d_fp_size;
};

/** Hash function for conversion sorts. */
template <uint32_t key>
struct CVC4_PUBLIC FloatingPointConvertSortHashFunction
{
  inline size_t operator()(const FloatingPointConvertSort& fpcs) const
  {
    FloatingPointSizeHashFunction f;
    return f(fpcs.d_fp_size) ^ (0x00005300 | (key << 24));
  }
}; /* struct FloatingPointConvertSortHashFunction */

/**
 * As different conversions are different parameterised kinds, there
 * is a need for different (C++) types for each one.
 */

/**
 * Conversion from floating-point to IEEE bit-vector (first bit represents the
 * sign, the following exponent width bits the exponent, and the remaining bits
 * the significand).
 */
class CVC4_PUBLIC FloatingPointToFPIEEEBitVector
    : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPIEEEBitVector(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPIEEEBitVector(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

/**
 * Conversion from floating-point to another floating-point (of possibly
 * different size).
 */
class CVC4_PUBLIC FloatingPointToFPFloatingPoint
    : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPFloatingPoint(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPFloatingPoint(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

/**
 * Conversion from floating-point to Real.
 */
class CVC4_PUBLIC FloatingPointToFPReal : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPReal(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPReal(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

/**
 * Conversion from floating-point to signed bit-vector value.
 */
class CVC4_PUBLIC FloatingPointToFPSignedBitVector
    : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPSignedBitVector(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPSignedBitVector(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

/**
 * Conversion from floating-point to unsigned bit-vector value.
 */
class CVC4_PUBLIC FloatingPointToFPUnsignedBitVector
    : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPUnsignedBitVector(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPUnsignedBitVector(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

class CVC4_PUBLIC FloatingPointToFPGeneric : public FloatingPointConvertSort
{
 public:
  /** Constructors. */
  FloatingPointToFPGeneric(uint32_t _e, uint32_t _s)
      : FloatingPointConvertSort(_e, _s)
  {
  }
  FloatingPointToFPGeneric(const FloatingPointConvertSort& old)
      : FloatingPointConvertSort(old)
  {
  }
};

/**
 * Base type for floating-point to bit-vector conversion.
 */
class CVC4_PUBLIC FloatingPointToBV
{
 public:
  /** Constructors. */
  FloatingPointToBV(uint32_t s) : d_bv_size(s) {}
  FloatingPointToBV(const FloatingPointToBV& old) : d_bv_size(old.d_bv_size) {}
  FloatingPointToBV(const BitVectorSize& old) : d_bv_size(old) {}

  /** Return the bit-width of the bit-vector to convert to. */
  operator uint32_t() const { return d_bv_size; }

  /** The bit-width of the bit-vector to converto to. */
  BitVectorSize d_bv_size;
};

/**
 * Conversion from floating-point to unsigned bit-vector value.
 */
class CVC4_PUBLIC FloatingPointToUBV : public FloatingPointToBV
{
 public:
  FloatingPointToUBV(uint32_t _s) : FloatingPointToBV(_s) {}
  FloatingPointToUBV(const FloatingPointToBV& old) : FloatingPointToBV(old) {}
};

/**
 * Conversion from floating-point to signed bit-vector value.
 */
class CVC4_PUBLIC FloatingPointToSBV : public FloatingPointToBV
{
 public:
  FloatingPointToSBV(uint32_t _s) : FloatingPointToBV(_s) {}
  FloatingPointToSBV(const FloatingPointToBV& old) : FloatingPointToBV(old) {}
};

/**
 * Conversion from floating-point to unsigned bit-vector value (total version).
 */
class CVC4_PUBLIC FloatingPointToUBVTotal : public FloatingPointToBV
{
 public:
  FloatingPointToUBVTotal(uint32_t _s) : FloatingPointToBV(_s) {}
  FloatingPointToUBVTotal(const FloatingPointToBV& old) : FloatingPointToBV(old)
  {
  }
};

/**
 * Conversion from floating-point to signed bit-vector value (total version).
 */
class CVC4_PUBLIC FloatingPointToSBVTotal : public FloatingPointToBV
{
 public:
  FloatingPointToSBVTotal(uint32_t _s) : FloatingPointToBV(_s) {}
  FloatingPointToSBVTotal(const FloatingPointToBV& old) : FloatingPointToBV(old)
  {
  }
};

/**
 * Hash function for floating-point to bit-vector conversions.
 */
template <uint32_t key>
struct CVC4_PUBLIC FloatingPointToBVHashFunction
{
  inline size_t operator()(const FloatingPointToBV& fptbv) const
  {
    UnsignedHashFunction< ::CVC4::BitVectorSize> f;
    return (key ^ 0x46504256) ^ f(fptbv.d_bv_size);
  }
}; /* struct FloatingPointToBVHashFunction */

/* Note: It is not possible to pack a number without a size to pack to,
 * thus it is difficult to implement output stream operator overloads for
 * FloatingPointLiteral in a sensible way. Use FloatingPoint instead. */

/** Output stream operator overloading for floating-point values. */
std::ostream& operator<<(std::ostream& os, const FloatingPoint& fp) CVC4_PUBLIC;

/** Output stream operator overloading for floating-point formats. */
std::ostream& operator<<(std::ostream& os,
                         const FloatingPointSize& fps) CVC4_PUBLIC;

/** Output stream operator overloading for floating-point conversion sorts. */
std::ostream& operator<<(std::ostream& os,
                         const FloatingPointConvertSort& fpcs) CVC4_PUBLIC;

}  // namespace CVC4

#endif /* CVC4__FLOATINGPOINT_H */