#ifndef STREAM_HPP
#define STREAM_HPP

#include <QString>

class Stream
{
public:
    enum class Status{
        Ok = 0, Error = 1, Warning = 2, Idle = 3
    };

    Stream();

    /// @brief Plays gst stream
    /// @param description pipeline description
    /// @param id widget id
    void Play(const QString& description, quintptr id);

    /// @brief Stops the stream
    void Stop();

    /// @brief Get the current stream status
    /// @return enum class Status
    Status GetStatus() const;

private:
    /// @brief Stream status enum
    Status _status;

    /// @brief Checks stream status
    void CheckStatus();
};

#endif