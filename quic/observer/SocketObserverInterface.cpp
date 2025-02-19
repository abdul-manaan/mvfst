/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <quic/observer/SocketObserverInterface.h>

#include <utility>

namespace quic {

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setOutstandingPackets(
    const std::deque<OutstandingPacket>& outstandingPacketsIn) {
  maybeOutstandingPacketsRef = outstandingPacketsIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setWriteCount(
    const uint64_t writeCountIn) {
  maybeWriteCount = writeCountIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setLastPacketSentTime(
    const TimePoint& lastPacketSentTimeIn) {
  maybeLastPacketSentTime = lastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setLastPacketSentTime(
    const folly::Optional<TimePoint>& maybeLastPacketSentTimeIn) {
  maybeLastPacketSentTime = maybeLastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setCwndInBytes(
    const folly::Optional<uint64_t>& maybeCwndInBytesIn) {
  maybeCwndInBytes = maybeCwndInBytesIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent::Builder&&
SocketObserverInterface::WriteEvent::Builder::setWritableBytes(
    const folly::Optional<uint64_t>& maybeWritableBytesIn) {
  maybeWritableBytes = maybeWritableBytesIn;
  return std::move(*this);
}

SocketObserverInterface::WriteEvent
SocketObserverInterface::WriteEvent::Builder::build() && {
  return WriteEvent(*this);
}

SocketObserverInterface::WriteEvent::WriteEvent(
    const WriteEvent::BuilderFields& builderFields)
    : outstandingPackets(*CHECK_NOTNULL(
          builderFields.maybeOutstandingPacketsRef.get_pointer())),
      writeCount(*CHECK_NOTNULL(builderFields.maybeWriteCount.get_pointer())),
      maybeLastPacketSentTime(builderFields.maybeLastPacketSentTime),
      maybeCwndInBytes(builderFields.maybeCwndInBytes),
      maybeWritableBytes(builderFields.maybeWritableBytes) {}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setOutstandingPackets(
    const std::deque<OutstandingPacket>& outstandingPacketsIn) {
  maybeOutstandingPacketsRef = outstandingPacketsIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setWriteCount(
    const uint64_t writeCountIn) {
  maybeWriteCount = writeCountIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setLastPacketSentTime(
    const TimePoint& lastPacketSentTimeIn) {
  maybeLastPacketSentTime = lastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setLastPacketSentTime(
    const folly::Optional<TimePoint>& maybeLastPacketSentTimeIn) {
  maybeLastPacketSentTime = maybeLastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setCwndInBytes(
    const folly::Optional<uint64_t>& maybeCwndInBytesIn) {
  maybeCwndInBytes = maybeCwndInBytesIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent::Builder&&
SocketObserverInterface::AppLimitedEvent::Builder::setWritableBytes(
    const folly::Optional<uint64_t>& maybeWritableBytesIn) {
  maybeWritableBytes = maybeWritableBytesIn;
  return std::move(*this);
}

SocketObserverInterface::AppLimitedEvent
SocketObserverInterface::AppLimitedEvent::Builder::build() && {
  return AppLimitedEvent(std::move(*this));
}

SocketObserverInterface::AppLimitedEvent::AppLimitedEvent(
    SocketObserverInterface::AppLimitedEvent::BuilderFields&& builderFields)
    : WriteEvent(builderFields) {}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setOutstandingPackets(
    const std::deque<OutstandingPacket>& outstandingPacketsIn) {
  maybeOutstandingPacketsRef = outstandingPacketsIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setWriteCount(
    const uint64_t writeCountIn) {
  maybeWriteCount = writeCountIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setLastPacketSentTime(
    const TimePoint& lastPacketSentTimeIn) {
  maybeLastPacketSentTime = lastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setLastPacketSentTime(
    const folly::Optional<TimePoint>& maybeLastPacketSentTimeIn) {
  maybeLastPacketSentTime = maybeLastPacketSentTimeIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setCwndInBytes(
    const folly::Optional<uint64_t>& maybeCwndInBytesIn) {
  maybeCwndInBytes = maybeCwndInBytesIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setWritableBytes(
    const folly::Optional<uint64_t>& maybeWritableBytesIn) {
  maybeWritableBytes = maybeWritableBytesIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setNumPacketsWritten(
    const uint64_t numPacketsWrittenIn) {
  maybeNumPacketsWritten = numPacketsWrittenIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::
    setNumAckElicitingPacketsWritten(
        const uint64_t numAckElicitingPacketsWrittenIn) {
  maybeNumAckElicitingPacketsWritten = numAckElicitingPacketsWrittenIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent::Builder&&
SocketObserverInterface::PacketsWrittenEvent::Builder::setNumBytesWritten(
    const uint64_t numBytesWrittenIn) {
  maybeNumBytesWritten = numBytesWrittenIn;
  return std::move(*this);
}

SocketObserverInterface::PacketsWrittenEvent
SocketObserverInterface::PacketsWrittenEvent::Builder::build() && {
  return PacketsWrittenEvent(std::move(*this));
}

SocketObserverInterface::PacketsWrittenEvent::PacketsWrittenEvent(
    SocketObserverInterface::PacketsWrittenEvent::BuilderFields&& builderFields)
    : WriteEvent(builderFields),
      numPacketsWritten(
          *CHECK_NOTNULL(builderFields.maybeNumPacketsWritten.get_pointer())),
      numAckElicitingPacketsWritten(*CHECK_NOTNULL(
          builderFields.maybeNumAckElicitingPacketsWritten.get_pointer())),
      numBytesWritten(
          *CHECK_NOTNULL(builderFields.maybeNumBytesWritten.get_pointer())) {}

SocketObserverInterface::AcksProcessedEvent::Builder&&
SocketObserverInterface::AcksProcessedEvent::Builder::setAckEvents(
    const std::vector<AckEvent>& ackEventsIn) {
  maybeAckEventsRef = ackEventsIn;
  return std::move(*this);
}

SocketObserverInterface::AcksProcessedEvent
SocketObserverInterface::AcksProcessedEvent::Builder::build() && {
  return AcksProcessedEvent(*this);
}

SocketObserverInterface::AcksProcessedEvent::AcksProcessedEvent(
    SocketObserverInterface::AcksProcessedEvent::BuilderFields builderFields)
    : ackEvents(*CHECK_NOTNULL(builderFields.maybeAckEventsRef.get_pointer())) {
}

} // namespace quic
