//
// Dispatcher.hpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003, 2004 Christopher M. Kohlhoff (chris@kohlhoff.com)
//
// Permission to use, copy, modify, distribute and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appears in all copies and that both the copyright
// notice and this permission notice appear in supporting documentation. This
// software is provided "as is" without express or implied warranty, and with
// no claim as to its suitability for any purpose.
//

/// Dispatcher concept.
/**
 * @par Implemented By:
 * asio::basic_demuxer @n
 * asio::basic_locking_dispatcher
 */
class Dispatcher
{
public:
  /// Request the dispatcher to invoke the given handler.
  /**
   * This function is used to ask the dispatcher to execute the given handler.
   *
   * @param handler The handler to be called. The dispatcher will make
   * a copy of the handler object as required. The equivalent function
   * signature of the handler must be: @code void handler(); @endcode
   */
  template <typename Handler>
  void dispatch(Handler handler);

  /// Request the dispatcher to invoke the given handler and return
  /// immediately.
  /**
   * This function is used to ask the dispatcher to execute the given handler,
   * but without allowing the dispatcher to call the handler from inside this
   * function.
   *
   * @param handler The handler to be called. The dispatcher will make
   * a copy of the handler object as required. The equivalent function
   * signature of the handler must be: @code void handler(); @endcode
   */
  template <typename Handler>
  void post(Handler handler);

  /// Create a new handler that automatically dispatches the wrapped handler
  /// on the dispatcher.
  /**
   * This function is used to create a new handler function object that, when
   * invoked, will automatically pass the wrapped handler to the dispatcher's
   * dispatch() function.
   *
   * @param handler The handler to be wrapped. The dispatcher will make a copy
   * of the handler object as required. The equivalent function signature of
   * the handler must be: @code void handler(); @endcode
   */
  template <typename Handler>
  implementation_defined wrap(Handler handler);
};
