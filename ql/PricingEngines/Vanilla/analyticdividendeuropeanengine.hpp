
/*
 Copyright (C) 2004 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file analyticdividendeuropeanengine.hpp
    \brief Analytic discrete-dividend European engine
*/

#ifndef quantlib_analytic_dividend_european_engine_hpp
#define quantlib_analytic_dividend_european_engine_hpp

#include <ql/Instruments/dividendvanillaoption.hpp>

namespace QuantLib {

    //! Analytic pricing engine for European options with discrete dividends
    /*! \ingroup vanillaengines */
    class AnalyticDividendEuropeanEngine 
        : public DividendVanillaOption::engine {
      public:
        void calculate() const;
    };

}


#endif
